#include<iostream>
using namespace std;
struct club{
    int number;
    int fa;
    int fb;
    int fc;
    int maxlike;
    int bumen;
    int sgema;
    int maxnum;
    int maxscore;
};

club n[10000];

int compare3(int a,int b,int c){
    int comp;
    if(a>=b){comp = 1;}
    else comp = 2;
    if(c>=comp){comp = 3;}
    return comp;
}




int compare31(int a,int b,int c){
    int comp1;
    if(a>=b){comp1 = a; }
    else comp1 = b;
    if(c>=comp1){comp1 = c;}
    return comp1;
}


int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,i,j,u;//i text number  j club number u same time
cin>>t;

int maxc[1000][1000];

for(i=1;i<=t;i++){
    cin>>n[i].number;

    n[i].maxnum = n[i].number/2;

    for(j=1;j<=n[i].number;j++){
    	cin>>n[j].fa>>n[j].fb>>n[j].fc;
    	//n[i].maxlike = compare3(n[j].fa,n[j].fb,n[j].fc);
    	maxc[i][j] = compare31(n[j].fa,n[j].fb,n[j].fc);
    	//n[i].bumen = n[i].maxlike;
    }

}

for(i=1;i<=t;i++){
    for(j=1;j<=n[i].number;j++){
    	if(maxc[i][j]==maxc[i][j+1]){
            u++;
            if(u<=n[i].maxnum){
                n[i].sgema += maxc[i][j];
            }
            if(u>n[i].maxnum){
                n[i].sgema += maxc[i][j];
            }
    	}else{n[i].sgema += maxc[i][j];}
    }

}

for(i=1;i<=t;i++){
    cout<<n[i].sgema<<endl;
    }

return 0;
}
