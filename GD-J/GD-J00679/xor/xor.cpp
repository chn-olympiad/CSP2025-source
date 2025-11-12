#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
string s;
long long ar[N];
bool arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,c=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		if(ar[i]==k){
			c++;
			arr[i]=true;
		}
	}
	for(int i=1;i<=n;){
		long long sum=0;
		bool f=false;
		int t;
		for(int j=i;j<=n;j++){
			if(!arr[j])sum=sum^ar[j];
			else{
				t=j;
				break;
			}
//			cout<<sum<<endl;
			if(sum==k){
				t=j;
//				cout<<111<<endl;
				f=true;
				break;
			}
		}
		if(f){
			c++;
			i=t+1;
//			cout<<"i"<<i<<endl;
		}else{
			i++;
		}
	}cout<<c;
	return 0;
}
