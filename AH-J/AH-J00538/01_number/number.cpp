#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("nember.out","w",stdout);
    string s;
    char a[10010],b[10010],max1='0';
    long long k=0,g;
    cin>>s;
    long long len=s.size();
    for(long long i=0;i<len;i++){
	    if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i];
			k++;
		}	
	}
	for(long long  i=0;i<k;i++){
		b[i]=a[i];
	}
	for(long long j=0;j<k;j++){
		for(int i=0;i<k;i++){
		    if(b[i]>max1&&b[i]<='9'){
		        max1=a[i];
		        g=i;
	        }
		}
	    cout<<max1;
	    b[g]='z';
	    max1='0';
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
