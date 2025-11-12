#include<bits/stdc++.h>
using namespace std;
int T;
int n;
long long num[6];
struct node{
    int nxmx;
    int mxnum;
    int mx;
}sss[10001];
int a,b,c;
int Num1,Num2,Num3;
bool cmp(node x,node y){
    return (x.mx-x.nxmx)>(y.mx-y.nxmx);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	for(int j=1;j<=T;j++){
        Num1=0;
        Num2=0;
        Num3=0;
        memset(sss,0,sizeof(sss));
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			sss[i].mx=max(max(a,b),c);
            if(a==sss[i].mx){
                sss[i].nxmx=max(b,c);
                sss[i].mxnum=1;
            }
            else if(b==sss[i].mx){
                sss[i].nxmx=max(a,c);
                sss[i].mxnum=2;
            }
            else{
                sss[i].nxmx=max(b,a);
                sss[i].mxnum=3;
            }
		}
		sort(sss+1,sss+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(sss[i].mxnum==1){
                if(Num1<k){
                    num[j]+=sss[i].mx;
                    Num1++;
                }
                else{
                    num[j]+=sss[i].nxmx;
                }
            }
            else if(sss[i].mxnum==2){
                if(Num2<k){
                    num[j]+=sss[i].mx;
                    Num2++;
                }
                else{
                    num[j]+=sss[i].nxmx;
                }
            }
            else if(sss[i].mxnum==3){
                if(Num3<k){
                    num[j]+=sss[i].mx;
                    Num3++;
                }
                else{
                    num[j]+=sss[i].nxmx;
                }
            }
            //cout<<sss[i].mx<<endl;
        }
	}
	for(int i=1;i<=T;i++){
        cout<<num[i]<<endl;
	}
	return 0;
}
