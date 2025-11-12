#include<bits/stdc++.h>
using namespace std;
int z[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,b;
    
    getline(cin,a);
	int sum=a.size();
    for(int i=0;i<=a.size();i++){
    	if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
    		continue;
		}
		else if(a[i]>='0'&&a[i]<='9'){
			sum--;
			b[i]=a[i];
			z[i]=(int)b[i]-'0';
		}
	}
	sort(z+0,z+a.size());
	for(int i=a.size()-1;i>=sum;i--){
		cout<<z[i];
	}
    return 0;	
}


