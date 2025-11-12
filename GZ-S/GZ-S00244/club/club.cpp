//李锴睿   都匀第一中学 
#include <bits/stdc++.h>
#define maxn 20005
using namespace std;
int t;
int zui1[maxn][3];
int zui2[maxn][3];
int n;
int m[maxn];
int ans[maxn];
int bu[3]={0};
int sheng[maxn/2];
int e,r;
struct s{
	int a1;//第一 
	int a2;//第二 
	int a3;//第三 
	int zai;//那个最大 
	bool jia;//是否加入 
}s[100000];
bool ban(int i){
    return bu[i]<(n/2);
}
void bi(int u){//内部比较 
	int shu[3]={0};
    shu[0]=s[u].a1;
    shu[1]=s[u].a2;
    shu[2]=s[u].a3;
    sort(shu,shu+3);
    zui1[u][0]=shu[2]; 
    
    if(shu[2]==s[u].a1)s[u].zai=0;
    if(shu[2]==s[u].a2)s[u].zai=1;
	if(shu[2]==s[u].a3)s[u].zai=2;
	//cout<<s[u].zai<<"ui"<<endl;
}
void bimax(){
	int big=0,cnt=0,k=0;
	for(int i=0;i<n;i++){
		//cout<<i<<endl;
		big=-1;
	    cnt=0;
		k=0;
	    while(cnt<n){
	        if(zui1[cnt][2]==-1){
	        	cnt++;continue;
			}
	        if(zui1[cnt][0]>big){
	     	   k=cnt;
	       	   big=zui1[cnt][0];
	       	   //cout<<big<<"hu"<<endl;
		    }
		     //cout<<cnt<<"!"<<k<<endl;
	      	cnt++;
	    }
		//cout<<big<<"o"<<endl;
	    zui2[i][0]=big;
	    zui2[i][1]=k;
	    zui1[k][2]=-1;
	    
    }
	 
}

void fen(){
	for(int i=0;i<maxn;i++){
		int l=s[zui2[i][1]].zai;
		
		if(s[zui2[i][1]].jia&&ban(l)){
		//	cout<<l<<"j"<<endl;
		    ans[r]+=zui2[i][0];
		   // cout<<ans[r]<<"!"<<endl;
		    bu[s[zui2[i][1]].zai]++; 
		    s[zui2[i][1]].jia=false;
		    
		}
	}
	r++;
}
void kong(){
	int tmp=0;
	for(int i=0;i<e;i++){
		if(s[i].jia)continue;
		else {
			sheng[tmp]=i;
			tmp++;
		}
		    
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	n=0;
        //cout<<n<<" "<<ans<<"o"<<endl;
    	memset(zui1,0,sizeof(zui1));
    	memset(zui2,0,sizeof(zui2));
	    memset(bu,0,sizeof(bu));
    	cin>>n;
    	e=n;
    	for(int i=0;i<n;i++){
    	    cin>>s[i].a1>>s[i].a2>>s[i].a3;
    	    s[i].jia=true;
    	    bi(i);//自身的最高满意度 
	    }
	    bimax();
	    fen();
	    
    }
    for(int i=0;i<r;i++)
        cout<<ans[i]<<endl;
	return 0;
}

