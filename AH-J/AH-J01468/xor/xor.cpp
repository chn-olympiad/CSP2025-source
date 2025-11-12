#include<bits/stdc++.h>
using namespace std;
struct str{
	int x,y;
};
int cmp(str a,str b){
	if(a.y!=b.y){
		return a.y<b.y;
	}else{
		return a.x>b.y;
	}
};
int a[500010],h[500010];
str oi[50000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i]=h[i-1]^a[i];
	}
	int cd=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((h[j]^h[i-1])==k){
				oi[cd].x=i;
				oi[cd].y=j;
				cd++;
			}
		}
	}
	sort(oi,oi+cd,cmp);
	int cnt=0;
	int i=0;
	for(int j=0;j<cd;j++){
		if(oi[j].x>i){
			cnt++;
			i=oi[j].y;
		}
	}
	cout<<cnt;
	return 0;
}
