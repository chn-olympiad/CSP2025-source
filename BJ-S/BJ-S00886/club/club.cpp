#include <bits/stdc++.h>
#include <iostream>

//printf("%d",int)
//scanf("%d",&int)

using namespace std;
int max_myself(int asdfasdf,int qwerqwer){
    if(asdfasdf>qwerqwer){
        return asdfasdf;
    }
    if(qwerqwer>=asdfasdf){
        return qwerqwer;
    }
}
int min_myself(int asdfasdf,int qwerqwer){
    if (asdfasdf>=qwerqwer){
        return qwerqwer;
    }
    if (asdfasdf<qwerqwer){
        return asdfasdf;
    }
}
int solution(int n,int tmp,int answer,int a1,int b1,int c1,int deltaab,int deltaac,int deltabc,int in){
    answer=0;
    tmp=0;
    int thepeople[n][4];

    for(int x=1;x==n;x++){
        for(int z=1;z==3;z++){
            scanf("%d",&in);
            thepeople[x][z]=in;
        }
        tmp=max_myself(thepeople[x][1],thepeople[x][2]);
        tmp=max_myself(thepeople[x][3],tmp);
        answer+=tmp;
        tmp=0;
        if (thepeople[x][1]>=thepeople[x][2]&&thepeople[x][1]>=thepeople[x][3]){
            a1+=1;
          // asd[x-1]={1,max_myself(thepeople[x][3],thepeople[x][2])==thepeople[x][3]?3:2,thepeople[x][1]-max_myself(thepeople[x][3],thepeople[x][2])} ;
        
        }

                if (thepeople[x][1]<=thepeople[x][2]&&thepeople[x][2]>=thepeople[x][3]){
            b1+=1;

            
        }

                if (thepeople[x][3]>=thepeople[x][2]&&thepeople[x][3]>=thepeople[x][1]){
            c1+=1;

            
        }
        while(a1>=n/2 || b1>=n/2 ||c1>=n/2){
        if(a1>=n/2){
            if(abs(thepeople[x][1]-thepeople[x][2])<=deltaab){
                b1+=1;
                a1-=1;
                answer-=deltaab;
                deltaab=abs(thepeople[x][1]-thepeople[x][2]);


            }
            else if(abs(thepeople[x][1]-thepeople[x][3])<=deltaac){
                a1-=1;
                c1+=1;
                answer-=deltaac;
                deltaac=abs(thepeople[x][1]-thepeople[x][3]);
            }
        }
        if (b1>=n/2){
                        if(abs(thepeople[x][2]-thepeople[x][3])<=deltabc){
                b1-=1;
                c1+=1;
                answer-=deltabc;
                deltabc=abs(thepeople[x][2]-thepeople[x][3]);
            }
            else if(abs(thepeople[x][2]-thepeople[x][1])<=deltaab){
                b1-=1;
                a1+=1;
                answer-=deltaab;
                deltaab=abs(thepeople[x][2]-thepeople[x][1]);
            }

        }
        if(c1>=n/2){
                                    if(abs(thepeople[x][3]-thepeople[x][2])<=deltabc){
                b1+=1;
                c1-=1;
                                answer-=deltabc;
                deltabc=abs(thepeople[x][2]-thepeople[x][3]);
            }
            else if(abs(thepeople[x][3]-thepeople[x][1])<=deltaab){
                c1-=1;
                a1+=1;
            }
                            answer-=deltaac;
                deltaac=abs(thepeople[x][1]-thepeople[x][3]);
        }
        
    }
    
    printf("%d",answer);
    printf("/n");

    }
}

int main(){
    freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    int t;
    int n;
    scanf("%d",&t);
    int in;
    int tmp;
    tmp=0;
    int a1,b1,c1;
    int answer;
    int deltaab,deltabc,deltaac;

    for(int i=1;i==t;i++){
            deltaab=0;
    deltabc=0;
    deltaac=0;
        solution(n,tmp,answer,a1,b1,c1,deltaab,deltaac,deltabc,in);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

