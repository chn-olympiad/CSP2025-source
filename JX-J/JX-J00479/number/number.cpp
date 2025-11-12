#include<bits/stdc++.h>
#define N 114514
using namespace std;
long long a[N];
bool cmpd(int c,int b){
    return c>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string n;
    cin>>n;
    long long j=0;
    for(long long i=0;i<10000;i++){
        if(n[i]=='1'){
            a[j]=1;
            j++;
        }
        else if(n[i]=='2'){
            a[j]=2;
            j++;
        }
        else if(n[i]=='3'){
            a[j]=3;
            j++;
        }
        else if(n[i]=='4'){
            a[j]=4;
            j++;
        }
        else if(n[i]=='5'){
            a[j]=5;
            j++;
        }
        else if(n[i]=='6'){
            a[j]=6;
            j++;
        }
        else if(n[i]=='7'){
            a[j]=7;
            j++;
        }
        else if(n[i]=='8'){
            a[j]=8;
            j++;
        }
        else if(n[i]=='9'){
            a[j]=9;
            j++;
        }
        else if(n[i]=='0'){
			a[j]=0;
			j++;
		}
    }
    sort(a,a+j,cmpd);
    for(int i=0;i<j;i++)cout<<a[i];
    return 0;
	}
