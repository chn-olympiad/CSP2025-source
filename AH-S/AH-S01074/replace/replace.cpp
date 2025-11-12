#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
string put[200000][2],in[5000000][2];
long long find(string aa,string a){
	long long A=0;
	while(aa.find(a)>=0 && aa.find(a)<aa.end()-aa.begin()){
		aa.erase(0,aa.find(a)+1);
		A++;
	}
	return A;
}
bool gimin(long long a,long long s){
	string k=in[s][0],num=put[a][0];
	if(k.find(num)!=-1)return 1;
	return 0;
}

int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>put[i][0]>>put[i][1];
	}
	for(int i=0;i<m;i++){
		cin>>in[i][0]>>in[i][1];
	}
	for(int i=0;i<m;i++){
		ans=0;
		for(int j=0;j<n;j++){
			if(gimin(j,i))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
