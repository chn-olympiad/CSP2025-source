#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
struct node{
	int num,dnum,id;
}s[N];
int n,k,cnt;
int a[N],dp[N],ans;
unordered_map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; //cout<<a[i]<<' ';
	}
	if(n==1){
		cout<<int(n==k);
		return 0;
	}
	if(n==2){
		if(k==0){
			cout<<max(int(a[1]==a[2]),int(a[1]==0)+int(a[2]==0))<<endl;
		}
		else{
			cout<<max(int(a[1]^a[2]==k),int(a[1]==k)+int(a[2]==k))<<endl;
		}
		return 0;
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		s[i].num=a[i]^s[i-1].num;
		s[i].id=i;
		s[i].dnum=k^s[i].num;
		if(mp.count(s[i].num)){
			mp[s[i].num]=min(mp[s[i].num],i);
		}
		else{
			mp[s[i].num]=i;
		}
		//cout<<s[i].id<<' '<<s[i].num<<' '<<s[i].dnum<<'\n';
	}
	int top=0;
	while(top<=n){
		int to=n+1;
		for(int i=top+1;i<=n;i++)
			if(mp.count(s[i].dnum)&&mp[s[i].dnum]>=i)
				to=min(to,mp[s[i].dnum]);
		ans++;
		top=to;
	}
	cout<<ans;
}
/*
4 2
2 1 0 3
*/
