#include<bits/stdc++.h>
using namespace std;
const int N=1000006;
int a[N],n;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int d;
	int j=1;
	int k=s.size();
	for(d=0;d<=k;d++){
		n=int(s[d])-48;
		if(n>=0&&n<=9){
			a[j]=n;
			j++;
		}
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
