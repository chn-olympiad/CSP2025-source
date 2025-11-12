#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    string e;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n][3],b[2],c,amax[n+1],num[n],text[2];
        bool bl[3];
        for(int i=0;i<n;i++){
        	
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i=0;i<n;i++){
        	for(int ii=0;ii<n;ii++){
    			amax[ii]=max(a[ii][0],a[ii][2]);
    			for(int iii=0;iii<=2;iii++){
    				if (amax[ii]==a[ii][iii]){
    					num[ii]=iii;
					}
				}
			}
        	int bbb;
			b[0]=0;b[1]=0;b[2]=0;
			if (b[num[1]]+1<=n/2){
				b[num[1]]=b[num[1]]+1;
				c=c+amax[0];
				amax[bbb]=0;
				bbb=0;
			}
			else{
				amax[bbb]=0;
				bbb=0;
			}
		}
        


        
		cout<<c<<endl;

    }
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
