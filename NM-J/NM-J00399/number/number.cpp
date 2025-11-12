#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,b;
    char c=0;
    int d=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' and a[i]<='9'){
            b[i]=a[i];
            d++;
        }
    }
    for(int i=0;i<=a.size();i++){
    	for (int j=0;j<=a.size();j++){
            if (b[j+1]>=b[j] and j+1<=a.size())
            {
            	c=b[j];
          	  	b[j]=b[j+1];
         	  	b[j+1]=c;
        	}
		}
    }
    cout<<b;
    for(int i=0;i<=d;i++){
        cout<<b[i];
    }
    return 0;
}
