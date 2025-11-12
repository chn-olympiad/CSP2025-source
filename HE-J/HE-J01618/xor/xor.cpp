#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
//°´Î»Òì»ò"^" 
int main()
{
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	
	long long mxn=-1,k,n,cnt=0,sm;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		sm=a[i];
		if (sm==k) cnt++;
		for (int j=i+1;j<=n;j++){
			//cout<<i<<" "<<j<<" ";
			sm=sm^a[j];
			//cout<<"sm "<<sm<<endl;
			if (sm==k){
				cnt++;
			}
			//cout<<"cnt "<<cnt<<endl<<endl;
		}	
	}
	
	cout<<cnt;
	return 0;
}
//98 99 100 97
