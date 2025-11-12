#include<bits/stdc++.h>
using namespace std;
char c;
vector<int>s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p=0;
    while(cin>>c){
        int num=c-48;
        if(num>=0&&num<=9){
            s.push_back(num);
            continue;
        }
        if(!(c>=97&&c<=122)){break;}
        ++p;
        if(p>=1000000)break;
    }

    int a=s.size();
    int k[a+3];
    int j=0,dd=0;
    for(auto i:s){
        k[++j]=i;
        if(i!=0)dd=1;
    }

    sort (k+1,k+j+1);
    for(int i=j;i>=1;i--){
        cout<<k[i];
    }
    return 0;
}
