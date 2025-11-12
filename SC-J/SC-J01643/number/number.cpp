#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100000],k=0,l=0;
	string b;
	cin>>b;
    for(int i=1;i<=10000000;i++){
    	if(b[i]==0&&b[i-1]==0){
    		break;
		}
		l++;
	}
	for(int i=0;i<l;i++)
	{  
			a[i]=b[i];	
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		
		
		cout<<char(a[i]);
	}

	
	return 0;
}