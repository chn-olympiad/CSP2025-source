#include<bits/stdc++.h>
using namespace std;
int n,a[5100],maxn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxn)maxn=a[i];
	}
	if(n==3){
		if((a[0]+a[1]+a[2]-maxn)*2>maxn){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(maxn==1){
		int ans=0;
		for(int i=4;i<=n;i++)ans+=n-i+1;
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
助我破鼎！
不好，他们要破鼎，全体捕妖队随我上鼎！根深蒂固！！！哪吒，不要挣扎了，你生来就是魔丸，这是命中注定！！！
我命由我不由天，是魔是仙，我自己说了才算！！！给我，破！！！
我的鼎！ 
*/