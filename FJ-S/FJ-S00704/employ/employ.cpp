#include<bits/stdc++.h>
using namespace std;

int n,m,temp;
typedef long long ll;
int dif[510];
ll miss[510];
ll hsh[510]={};
const ll M=998244353;
int main(){
	freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	//真假t4这个
	cin>>n>>m;
	cin.get();
	for(int i=0;i<n;++i){
		dif[i]=cin.get();
	}
	for(int i=0;i<n;++i){
		cin>>temp;
		hsh[temp]++;
	}
	int mi_p=0;
	for(int i=0;i<n;++i){
		if(dif[i]==0){
			mi_p++;
		}
		miss[mi_p]++;
	}
	//剩下的mi_p是最大的没通过人数
	int least=0;
	for(int i=mi_p+1;i<n;++i){
		least+=hsh[i];
	}
	temp=1;
	for(int i=2;i<=n;++i){
		temp=temp*i%M;
	}
	cout<<temp%M;
	
	return 0;
}
