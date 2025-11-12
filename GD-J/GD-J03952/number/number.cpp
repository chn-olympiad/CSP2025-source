#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string a;
int num[N],k;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int wei=a.size();
	for(int i=0;i<wei;i++){
		if(!(a[i]>='a'&&a[i]<='z')){
			num[k++]=a[i]-'0';
		}
	}
	sort(num,num+k,cmp);
	for(int i=0;i<k;i++)cout<<num[i];
	return 0;
}
