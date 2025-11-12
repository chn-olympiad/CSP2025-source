#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
	    if(i>='0'&&i<='9'){
			a[k]=i;
			k++;
			}	
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(a[j]>max1){
				max1=a[j];
				a[j]='0';
			}
		}
		cout<<max1;
		max1='0';
	}
    fclose(stdin);
    fclose(stdout);
    return 0;

}
