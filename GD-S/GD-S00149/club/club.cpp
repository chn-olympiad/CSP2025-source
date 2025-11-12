#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct people{
	int x,y,z;
	bool operator < (people other){
		return x>other.x;
	}
}arr[100010];
int join[4];
ll ans = 0;
int getin(){
	char c;
	int flag = 1;
	int ans = 0;
	while(c<'0'||c>'9'){
		if(c=='-') flag = -1; 
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		ans *= 10;
		ans += c-'0'; 
		c = getchar();
	}
	return ans*flag;
}
void putout(ll x,bool _=true){
	if(x==0){
		if(_) putchar('0');
		return ;
	}
	if(x<0){
		putchar('-');
		x = -x;
	}
	putout(x/10,false);
	putchar(x%10+'0');
}
void dfs(int n,int index,ll satisfy){
	if(index==n+1){
		ans = max(ans,satisfy);
		return ;
	}
	if(join[1]<n/2){
		join[1]++;
		dfs(n,index+1,satisfy+arr[index].x);
		join[1]--;
	}
	if(join[2]<n/2){
		join[2]++;
		dfs(n,index+1,satisfy+arr[index].y);
		join[2]--;
	}
	if(join[3]<n/2){
		join[3]++;
		dfs(n,index+1,satisfy+arr[index].z);
		join[3]--;
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=getin();
    bool flaga=2,flagb=1;
    while(t--){
        ans = 0;
        int n=getin();
        
        for(int i=1;i<=n;i++){
        	arr[i].x=getin();
			arr[i].y=getin();
			arr[i].z=getin();
			if(arr[i].y!=0||arr[i].z!=0) flaga = 0;
		}
		if(n<=30) dfs(n,1,0);
		else if(flaga){
			// 性质A
			sort(arr+1,arr+1+n);
			for(int i=1;i<=n/2;i++) ans += arr[i].x;	
		}
		else if(flagb){
			// 我好像不会写 QAQ 
		}
        
        putout(ans);
        putchar('\n');
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
