#include<bits/stdc++.h>
using namespace std;
int b[1000050];
bool cmp(int d,int c){
	return d>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	int num=1;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			b[num]=a[i]-'0';
			num++;
		}
	}
	num--;
	sort(b+1,b+num+1,cmp);
	if(b[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=num;i++){
		cout<<b[i];
	}
	return 0; 
} 
