#include<bits/stdc++.h>
using namespace std;
int q[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'){
			q[j]=1;
			j++;
		}
		if(a[i]=='2'){
			q[j]=2;
			j++;
		}
		if(a[i]=='3'){
			q[j]=3;
			j++;
		}
		if(a[i]=='4'){
			q[j]=4;
			j++;
		}
		if(a[i]=='5'){
			q[j]=5;
			j++;
		}
		if(a[i]=='6'){
			q[j]=6;
			j++;
		}
		if(a[i]=='7'){
			q[j]=7;
			j++;
		}
		if(a[i]=='8'){
			q[j]=8;
			j++;
		}
		if(a[i]=='9'){
			q[j]=9;
			j++;
		}
		if(a[i]=='0'){
			q[j]=0;
			j++;
		}
	}
	sort(q,q+j+1);
	for(int i=j;i>0;i--){
		cout<<q[i];
	}
	return 0;
}
