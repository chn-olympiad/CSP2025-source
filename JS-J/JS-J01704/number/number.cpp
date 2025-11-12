#include<bits/stdc++.h>
using namespace std;
char c;
string bucket[12]={"","","","","","","","","","",""};
int n,len;
int main(){
	//The below are freopens.
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    //Done.
    //input to be fixed
    do{
		scanf("%c",&c);
		if('0'<=c&&c<='9')bucket[c-'0']+=c;
	}while(('0'<=c&&c<='9')||('a'<=c&&c<='z'));
    for(int i=9;i>=0;i--){
		cout<<bucket[i];
	}
    return 0;
}
