#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n,q;
struct node{
	int d,a,b,len;
	bool operator < (const node & x)const{
		return d < x.d;
	}
}t[N]; 
void input(int cn){
	char a;
	int i = 0;
	while(1){
		i++;
		a=getchar();
		if(a == 'b'){
			t[cn].d = i;
			t[cn].a = i-1;
		}
		if(a == ' ')break;
	}
	t[cn].len = i-1;
	i = 0;
	while(1){
		i++;
		a=getchar();
		if(a == 'b'){
			t[cn].d -= i;
			t[cn].b = t[cn].len-i;
		}
		if(a == '\n')break;
	}
}
int binary1(int l,int r,int v){
	while(l < r){
		int mid = (l+r) >> 1;
		if(t[mid].d < v)l = mid+1;
		else r = mid;
	}
	if(t[l].d!=v)return -1;
	return l;
}
int binary2(int l,int r,int v){
	while(l < r){
		int mid = (l+r+1) >> 1;
		if(t[mid].d <= v)l = mid;
		else r = mid-1;
	}
	
	if(t[l].d!=v)return -1;
	return l;
}
void work2(){
	getchar();
	for(int i = 1;i <= n;i++){
		input(i);
	}
	sort(t+1,t+n+1);
	for(int i = 1;i<=q;i++){
		char c;
		int j = 0,len,a,b,d;
		while(1){
			j++;
			c=getchar();
			if(c == 'b'){
				d = j;
				a = j-1;
			}
			if(c == ' ')break;
		}
		len = j-1;
		j = 0;
		while(1){
			j++;
			c = getchar();
			if(c == 'b'){
				d -= j;
				b = len-j;
			}
			if(c == '\n')break;
		}
	
		int id1 = binary1(1,n,d);
		int id2 = binary2(1,n,d);
		if(id1 == -1 || id2 == -1){
			printf("0\n");
			continue;
		}else{
			int ans = 0;
			for(int k = id1;k <= id2;k++){
				if(t[k].a <= a && t[k].b <= b)ans++;
			}
			printf("%d\n",ans);
		}
	}
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	work2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
2 1
aaba abaa
ab ba
aaaaabaaaaa aaaabaaaaaa
*/
