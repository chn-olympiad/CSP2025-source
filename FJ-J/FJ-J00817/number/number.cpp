#include<bits/stdc++.h>
using namespace std;
string a,m;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			
		}else{
			a[i]-=a[i];
		}
		
	}
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				
			}
		}	
	
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
