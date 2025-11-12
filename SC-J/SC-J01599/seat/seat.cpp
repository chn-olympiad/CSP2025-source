#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n,m;
pair<int,bool> a[105];
bool cmp(pair<int,bool> a,pair<int,bool> b){
	return a.first>b.first;
}
int main(){
	fre("seat");
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i].first;
		if(i==1)a[i].second=1;
		else a[i].second=0;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1,row=1,line=1;i<=len;i++){
		if(a[i].second==1){
			cout<<line<<' '<<row;
		}
		if(line%2==0)row--;
		else row++;
		if(row==n+1){
			row=n,line++;
		}
		else if(row==0){
			row=1,line++;
		}
	}
	return 0;
}