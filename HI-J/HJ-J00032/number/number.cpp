#include<bits/stdc++.h>
using namespace std;
int b[10000000],y=0;
int main(){
	
   freopen("number.in", "r", stdin);
   freopen("number.out", "w",stdout);
	string a;
	cin>>a;
	
	for(int i=0;i<=a.size();i++){
		if(a[i]=='0' or a[i]=='1' or a[i]=='2' or a[i]=='3' or a[i]=='4' or a[i]=='5' or a[i]=='6' or a[i]=='7' or a[i]=='8' or a[i]=='9'){
			b[i]=a[i]-'0';
			
			
			y++;	
			if(a.size()==1)cout<<b[i];	
		}		
	}	
	
	sort(b,b+y+1);

    for(int i=y-1;i>0;i--){
			
		cout<<b[i];			
				
	}		
    return 0;
}

