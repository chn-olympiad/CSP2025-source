#include<bits/stdc++.h>
using namespace std;
int t,an;
int sa[100010][3];
int d[3];
vector<int> v;
int select(int pe,int dc,int a,int su){
    if(d[dc]>su/2) return 0;
    a+=sa[pe][dc];
    d[dc]++;
    return a;
}
int dfs(int pe,int dc,int su){
    if(pe>=su) return 0;

//    ans=max(select(pe,dc,ans),select(pe,dc,ans))
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>t;
    while(t--){
		int n;
		cin>>n;
		an=0;
		d[0]=0;d[1]=0;d[2]=0;
		v.clear();
//		int d[3]={0};
        bool f=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>sa[i][j];
            }
            if(sa[i][1]!=0 || sa[i][2]!=0) f=false;
            v.push_back(sa[i][0]);
        }
        if(f){
            sort(v.begin(),v.end());
            for(int i=n/2;i<=n;i++) an+=v[i];
        }
        if(n==2){
            int x0=0,y0=0,x1=1,y1=1,x2=2,y2=2;
            if(sa[0][0]<sa[0][1] && sa[0][1]<sa[0][2]){
                x0=2;
                x1=1;
                x2=0;
            }else if(sa[0][0]<sa[0][2] && sa[0][2]<sa[0][1]){
                x0=1;
                x1=2;
                x2=0;
            }else if(sa[0][1]<sa[0][2] && sa[0][2]<sa[0][0]){
                x0=0;
                x1=2;
                x2=1;
            }else if(sa[0][2]<sa[0][0] && sa[0][0]<sa[0][1]){
                x0=1;
                x1=0;
                x2=2;
            }else if(sa[0][1]<sa[0][0] && sa[0][0]<sa[0][2]){
                x0=2;
                x1=0;
                x2=1;
            }

            if(sa[1][0]<sa[1][1] && sa[1][1]<sa[1][2]){
                y0=2;
                y1=1;
                y2=0;
            }else if(sa[1][0]<sa[1][2] && sa[1][2]<sa[1][1]){
                y0=1;
                y1=2;
                y2=0;
            }else if(sa[1][1]<sa[1][2] && sa[1][2]<sa[1][0]){
                y0=0;
                y1=2;
                y2=1;
            }else if(sa[1][2]<sa[1][0] && sa[1][0]<sa[1][1]){
                y0=1;
                y1=0;
                y2=2;
            }else if(sa[1][1]<sa[1][0] && sa[1][0]<sa[1][2]){
                y0=2;
                y1=0;
                y2=1;
            }
            if(x0!=y0) an=sa[0][x0]+sa[1][y0];
            else if(sa[0][x0]>sa[1][y0]) an=sa[0][x0]+sa[1][y1];
            else an=sa[0][x1]+sa[1][y0];
        }
        cout<<an;
	}

    fclose(stdin);
    fclose(stdout);
    return 0;
}
