#include<bits/stdc++.h>
using namespace std;
int m1[100005],m2[100005],m3[100005];
int ans[100005];
bool cmp(int x,int y){
	return x>y;
}
bool cmd(int x,int y){
	return x>y;
}
bool cmb(int x,int y){
	return x>y;
}
int main(){
	//*
    freopen("club.out","r",stdin);
    freopen("club.in","w",stdout);//*/
    int t;
    cin>>t;
    long long s=0,wei=0;
    /*
    for(int i=1;i<=5;i++){
    	cin>>m1[i];
	}
	sort(m1+1,m1+6,cmp);
	for(int i=1;i<=5;i++){
    	cout<<m1[i];
	}//*/

    for(int Ci=1;Ci<=t;Ci++){
//*
		int n;cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>m1[i]>>m2[i]>>m3[i];
		}
		sort(m1+1,m1+n+1,cmp);int w[4]={1,1,1,1};
		sort(m2+1,m2+n+1,cmd);
		sort(m3+1,m3+n+1,cmb);
		int sen=n/2;
		for(int j=1;j<=n;j++){
			int rrr=max(m1[w[1]],max(m2[w[2]],m3[w[3]]));
			if(rrr=m1[w[1]]&&w[1]!=sen){
				w[1]++;
			}else{
				if(rrr=m2[w[2]]&&w[2]!=sen){
					w[2]++;
				}else{
					if(rrr=m3[w[3]]&&w[3]!=sen){
						w[3]++;
					}
				}
			}
			s+=rrr;
		}
		ans[Ci]=s;     //*/
	}
    for(int i=1;i<=t;i++){
    	cout<<ans[i]<<endl;
	}
    //*/
    //*
    pclose(stdin);
    pclose(stdout);//*/
    return 0;
}
