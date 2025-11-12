#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int t;
int main(){
freopen("club.in","r",std.in);
freopen("club.out","w",std.out);
    cin>>t;
    int d[9178];
    int g=t;
    while(t){
        t--;
        int n;
        cin>>n;
        vector<int> va,vs,vd,wa,ws,wd;
        int cnta=0,cnts=0,cntd=0;
        for(int i=1;i<=n;i++){      //finish the ru
            int a;
            cin>>a;
            va.push_back(a);
            cin>>a;
            vs.push_back(a);
            cin>>a;
            vd.push_back(a);
        }
        
        for(int i=0;i<n;i++){
            if(va[i]>=vs[i]&&va[i]>=vd[i]) {
				if(cnta>n/2){
					for(int j=0;j<n/2;j++){
						if(wa[j]<va[i]) wa[i]=va[i];
					}
				}
				else {wa.push_back(va[i]);
					cnta++;
				}
			}
            else if(vs[i]>=va[i]&&vs[i]>=vd[i]){
				if(cnts>n/2){
					for(int j=0;j<n/2;j++){
						if(ws[j]<vs[i]) ws[j]=vs[i];
					}
				}
				else {ws.push_back(vs[i]);
					cnts++;
				}
			}
            else if(vd[i]>=va[i]&&vd[i]>=vs[i]){
				if(cntd>n/2){
					for(int j=0;j<n/2;j++){
						if(wd[j]<vd[i]) {
							wd[j]=vd[i];
						}
					}
				}
				else {wd.push_back(vd[i]);
					cntd++;
				}
			}
		}
        for(int i=0;i<cnta;i++){
			d[t]+=wa[i];
		}
		for(int i=0;i<cnts;i++){
			d[t]+=ws[i];
		}
		for(int i=0;i<cntd;i++){
			d[t]+=wd[i];
		}
    }
    for(int i=g-1;i>=0;i--){
        cout<<d[i]<<endl;
    }
return 0;
}

