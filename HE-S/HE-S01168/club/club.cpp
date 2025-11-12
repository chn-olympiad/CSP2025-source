#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","w",stdin);
    freopen("club.out","r",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,numa=0,numb=0,numc=0,sum=0;
        cin>>n;
        int a1[10010],a2[10010],a3[10010];
        for(int j=1;j<=n;j++){

            cin>>a1[j]>>a2[j]>>a3[j];

        }

        if(n>2){
		sort(a1+1,a1+n+1,cmp);
        sort(a2+1,a2+n+1,cmp);
        sort(a3+1,a3+n+1,cmp);
            for(int z=1;z<=n/2;z++){
                numa+=a1[z];
                numb+=a2[z];
                numc+=a3[z];
            }
            if(numa>numb>numc){
                for(int p=1;p<=n/4;p++){
                    sum=sum+a2[p]+a3[p];
                }
                cout<<numa+sum<<endl;
            }else if(numb>numa>numc){
                for(int p=1;p<=n/4;p++){
                    sum=sum+a1[p]+a3[p];
                }
                cout<<numb+sum<<endl;
            }else if(numc>numa>numb){
                for(int p=1;p<=n/4;p++){
                    sum=sum+a1[p]+a2[p];
                }
                cout<<numc+sum<<endl;
            }
        }else{
        	int kj[100010];
            for(int v=1;v<=6;v++){
            	if(v==1){
            		kj[i]=a1[1]+a2[2];
				}else if(v==2){
					kj[i]=a1[1]+a3[2];
				}else if(v==3){
					kj[i]=a2[1]+a1[2];
				}else if(v==4){
					kj[i]=a2[1]+a3[2];
				}else if(v==5){
					kj[i]=a3[1]+a1[2];
				}else{
					kj[i]=a3[1]+a2[2];
				}
			}
			sort(kj+1,kj+100010+1);
			cout<<kj[1];
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
