#include<bits/stdc++.h>
using namespace::std;
const int N=1e5+5;
int n,t,cnt,maxx;
int a[N][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int b[3];
    int i,j,o=0;
    cin>>t;
    for(int j=0;j<t;j++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int u=0;u<3;u++){
                scanf("%d",&a[i][u]);
            }
        }
//        for(int i=0;i<3;i++){
//        	while(b[i][o]<n/2){
//        		for(int o=0;o<n;o++){
//        			maxx=max(a[o][i],maxx);
//				}
//            	cnt+=maxx;
//            	cout<<maxx<<" << "<<endl;
//            	for(int q=0;q<n;q++){
//            		for(int w=0;w<3;w++){
//            			if(a[o][i]==maxx) a[o][i]==0;
//					}
//				}
//            	maxx==0;
//           		b[i][o]++;
//           	}
//        }
		for(int i=0;i<n;i++){
			for(int k=0;k<3;k++){
				maxx=max(a[i][k],maxx);
			}
           	cnt+=maxx;
           	maxx=0;
        }
        cout<<cnt<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

