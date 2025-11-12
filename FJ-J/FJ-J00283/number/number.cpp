#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10000];
	string s;
	int i,j=0;
	cin>>s;
	int n=sizeof(s);
//	cout<<n<<endl;
	for(i=0;i<n;i++){
		if(s[i]>=48 and s[i]<=57){
			j++;
			a[j]=s[i];
		}
	}
//	for(j=1;j<=n;j++)
//		cout<<a[j];
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
		cout<<a[i];
	return 0;
}
