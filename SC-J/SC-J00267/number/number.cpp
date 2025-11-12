#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("","number.in",stdin);
	string a;cin>>a;
	int c=a.size(),num=0;
	string b;
	for(int i=0;i<c;i++){
		if(a[i]<=127&&a[i]>=91){
			continue;
		}else{
			int k=a[i];
			b[num]=k;
			num++;
		}
	}
	int x[num+5];
	for(int i=0;i<num;i++){
		b[i]=x[i];
	}
	sort(x,x+num+1);
	for(int i=num-1;i>=0;i--){
		cout<<x[i];
	}
	freopen("","number.out",stdout);
	return 0;
}