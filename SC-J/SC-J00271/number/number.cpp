#include<bits/stdc++.h>
using namespace std;
struct Node{
	int n;
}num[1000005];
bool cmp(Node a,Node b){
	return a.n>b.n;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.length(),sumi=0;
	for(int i=0;i<l;i++){
		if(a[i]>='0' && a[i]<='9'){
			num[sumi++].n = a[i]-'0';
		}
	}
	sort(num,num+sumi,cmp);
	for(int i=0;i<sumi;i++) cout<<num[i].n;
	cout<<endl;
	return 0;
}