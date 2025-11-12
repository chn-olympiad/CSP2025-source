#include<bits/stdc++.h> 
using namespace std;
string a;
bool mark;
int num[1000004];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();

	for(int i=0;i<len;i++){
		if(a[i]>='0' and a[i]<='9'){
			if(a[i]!=0) mark=1;
			num[cnt++]=a[i]-'0';
		}
	}
	sort(num,num+cnt);
	if(mark==0) return 0;
	for(int i=cnt-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
