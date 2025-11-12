#include<bits/stdc++.h>
using namespace std;
int a[15];
string b;
int c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    c=b.size();
    for(int i=0;i<=c;i++){
        if(b[i]=='1'){
            a[1]++;
        }else if(b[i]=='2'){
            a[2]++;
        }else if(b[i]=='3'){
            a[3]++;
        }else if(b[i]=='4'){
            a[4]++;
        }else if(b[i]=='5'){
            a[5]++;
        }else if(b[i]=='6'){
            a[6]++;
        }else if(b[i]=='7'){
            a[7]++;
        }else if(b[i]=='8'){
            a[8]++;
        }else if(b[i]=='9'){
            a[9]++;
        }else if(b[i]=='0'){
            a[0]++;
        }
    }
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
