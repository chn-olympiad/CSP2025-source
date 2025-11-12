#include<bits/stdc++.h>
using namespace std;
string a;
int s[100000024],sum;
bool coco(int v,int w){
	if(v>w)return 1;
	return 0;
}int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	cin>>a;
 	for(int i=0;i<a.size();i++){
 		if('0'<=a[i]&&a[i]<='9')s[++sum]=int(a[i]-'0');
	}sort(s+1,s+1+sum,coco);
	for(int i=1;i<=sum;i++)cout<<s[i];
	cout<<endl;
	return 0; 	
}
