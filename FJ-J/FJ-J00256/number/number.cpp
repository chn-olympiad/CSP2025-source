#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10000010];
string b;
char c; //0=48 9=57
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int l=b.size();
	int j=0;
	for(int i=0;i<l;i++){
		if(b[i]>=48 && b[i]<=57){
		//	cout<<b[i]<<endl;
			a[j]=b[i]-48;
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	
	return 0;
} 
