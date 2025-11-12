#include<bits/stdc++.h>
using namespace std;
bool cmp(int h,int k){
	return h>k;
}
int b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int num=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			num++;
			b[num]=a[i]-'0';
		}
	}
	sort(b+1,b+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<b[i];
	}
	return 0;
}
