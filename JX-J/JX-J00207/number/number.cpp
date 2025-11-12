#include<bits/stdc++.h>
using namespace std;
string a;
long long b[100005];
long long x=0,n=0,m=0,c=0,d=0,e=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	m=a.size();
	while(n>0){
		for(int i=0;i<m;i++){
			if(a[i]<='9'){
				b[e]=a[i];
				e++;
				d++;
				
				} 
			n--;
			}
		}
		for(int i=0;i<d;i++){
			if(a[i]=='9') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='8') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='7') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='6') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='5') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='4') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='3') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='2') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='1') cout<<a[i];
			}
		for(int i=0;i<d;i++){
			if(a[i]=='0') cout<<a[i];
			}
			return 0;
}
