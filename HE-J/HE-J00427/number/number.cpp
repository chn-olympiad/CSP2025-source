#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
      return a>b;
}
int c=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n=a.size();
    int b[n];
    for(int i=0;i<n;i++){
	    if(a[i]>='a' && a[i]<='z'){
            continue;
        }
        else{
            b[i]=a[i]-'0';
            c++;
        }
    }
    sort(b,b+c,cmp);
    for(int i=0;i<c;i++){
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
