#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[5005];

string ten_to_two(int num){
	string str="",ans="";
	int pos=0;
	while(num){
		str+=char(num%2+'0');
		num/=2;
	}
	for(int i=0;i<str.size();i++){
		ans+=str[str.size()-1-i];
	}
	return ans;
}

int xr(int x,int y){
	string nx=ten_to_two(x),ny=ten_to_two(y),ans="";
	if(nx.size()>ny.size()){
		string tmp=ny;
		int si=ny.size();
		ny="";
		for(int i=1;i<=nx.size()-si;i++){
			ny+='0';
		}
		ny+=tmp;
	}else{
		string tmp=nx;
		int si=nx.size();
		nx="";
		for(int i=1;i<=ny.size()-si;i++){
			nx+='0';
		}
		nx+=tmp;
	}
	int ans2=0,mi=0;
	for(int i=0;i<=max(nx.size(),ny.size())-1;i++){
		if((nx[i]=='0' && ny[i]=='1' )||( nx[i]=='1' && ny[i]=='0') ||(nx[i]==' '&&ny[i]!=' ') ||(nx[i]!=' '&&ny[i]==' ')){
			ans+='1';
		}else{
			ans+='0';
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		ans2+=(ans[i]-'0')*pow(2,mi);
		//cout<<(ans[i]-'0')*pow(2,mi)<<"    "<<ans2<<endl;
		mi++;
	}
	return ans2;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,sum=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i];
			for(int k=i;k<j;k++){
				//cout<<k<<" ";
				sum=xr(sum,a[k+1]);
				cout<<"sum"<<xr(sum,a[k+1])<<", k="<<k<<endl;
				if(sum==k) ans++;
			}cout<<endl;
		}
	}cout<<ans-1;
	return 0;
}
