#include<iostream>
#include<cmath>
using namespace std;
long long n,k;
long long a[500010];
string a1[500010],k1;
long long cnt;
bool vis[500010];
/*void ss(){
	long long p=pow(2,20);
	for(int i=1;i<=n;i++){
		long long s=p;
		long long t=a[i];
		while(t){	
			a1[i]+=(t/s+'0');
			t%=s;
			s/=2;
		}
	}
}
void stt(){
	long long s=pow(2,20);
	long long t=k1;
	while(t){	
		k1+=(t/s+'0');
		t%=s;
		s/=2;
	}
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	//ss();stt();
	/*for(int i=1;i<=n;i++){
		if(a1[i]==k1)cnt++,vis[i]=1;
	}*/
	/*for(int i=1;i<n;i++){
		int sss=a[i];
		if(sss==k)cnt++;
		for(int j=i+1;j<=n;j++){
			sss^=a[j];
			cout<<sss<<endl;
			if(sss==k)cnt++;
		}
	}*/
	for(int i=1;i<=n;i++)if(a[i]==k)cnt++,vis[i]=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int ttt=0;
			int kkk=a[i];
			while(vis[i+ttt+1]==0&&kkk!=k)ttt++,kkk^=a[i+ttt],vis[i+ttt]=1;
			if(kkk==k)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}