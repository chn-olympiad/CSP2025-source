#include<bits/stdc++.h>
using namespace std;
int come,employ,day,ans;
char ti[503];
int pac[503];
int luyong=0,giveup=0;


int ping(int a){
if(a<=day){

    int b=0;
    int pac2[503];
    int luyong2;
    luyong2=luyong;
        for(int i=1;i<=come;i++){
            if(pac[i]-giveup+luyong<0){b++;}
        }
        giveup=b;//jisuanfangqizongrenshu

        for(int i=0;i<=502;i++){
        	pac2[i]=pac[i];
		}

        for(int i=1;i<=come;i++){
            if(pac[i]-giveup<0){continue;}
            else{
                if(ti[a]=='0'){pac[i]=-1;ping(a+1);}
                else{luyong++;pac[i]=-1;ping(a+1);}
            }
            giveup=b;
            for(int i=0;i<=502;i++){
        	pac[i]=pac2[i];
        	luyong=luyong2;
		}
		 }



}
else{
if(luyong>=employ){ans++;}


}
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
scanf("%d %d",&come,&employ);
scanf("%s",ti);
day=strlen(ti);
for(int q=1;q<=come;q++){
    scanf("%d",&pac[q]);
}
ping(1);
cout<<ans%998244353;
}
