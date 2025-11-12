#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[1000010],num;
long long jly;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int y=a[i];
		if(a[i]==k){
			num++;
		}
		else{
			jly=a[i];
			for(int j=i+1;j<=n;j++){
				jly=jly^a[j];
				if(jly==k){
//					cout<<i<<" "<<j<<endl;
					num++;
					i=j;
					break;
				}
			}
		}
	}
	cout<<num<<endl;
	return 0;
} 
