#include<bits/stdc++.h>
using namespace std;
int a[100001];
bool b[10001]={1};
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0,sum;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(b[j])
				sum=(sum^a[j]);
			b[j]=!b[j];
		}
		if(sum==k)
			num++;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}