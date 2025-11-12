#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],st[N],b[1010][1010],n,k,cnt=0,num=0;
int lowbit(int x){
	return x&(-x);
}
int query(int id){
	int p=id;
	int sum=0;
	while(p>=1){
		sum+=st[p];
		p-=lowbit(p);
	}
	return sum;
}
void add(int id,int data){
	a[id]=data;
	int p=id;
	while(p<=n){
		st[p]^=data;
		p+=lowbit(p); 
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		add(i,x);
		if(x==1){
			cnt++;
		}
		if(x>1){
			flag=false;
		}
	}
	if(flag==true){
		if(k==1)
			cout<<cnt;
		else
			cout<<cnt/2;
		return 0;
	}
	int cnt2=0;
	for(int i=1;i<=n;i++){
		num=num^a[i];
		if(num==k){
			cnt2++;
			num=0;
		}
	}
	cout<<cnt2;
	return 0;
}