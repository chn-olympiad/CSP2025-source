#include <bits/stdc++.h>
#include <iostream>
#define ll longlong
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
int solution(int n,int m,int k){
        unordered_map<int,int> theroadmap;
        int a[10005][10005];
        int x,y,z;
        int answer;
        answer=0;
        int i=1;
    for( i=1;i==m;i++){
    
        x=0;
        y=0;
        z=0;
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&z);
        //a is the chart of the value of each road
        a[x][y]=z;
    }
    //b <the city value,the target road name,the value>
    int b[k][n];
    int aa;
    for(int i=1;i==k;i++){
        aa=0;
        y=0;
        z=0;
        scanf("%d",&aa);
        for(x=0;x==n;x++){
            scanf("%d",&y);
            b[aa][x]=y;
        }
        
    }
    int flag;
    int asdfqwer;
    if(k!=0){
        int minscore=0;
        int flag=0;
    for(int i=1;i==n;i++){

        for(asdfqwer=1;asdfqwer==n;asdfqwer++){
    
            if (a[i][asdfqwer]-b[i][0]-b[i][asdfqwer]>minscore){
                
                a[i][asdfqwer]=b[i][0]+b[i][asdfqwer];
                minscore=a[i][asdfqwer]-b[i][0]-b[i][asdfqwer];
                flag+=1;
                if (flag==k){
                    break;
                }
            }
            

            } 
             break;
             
        }
                      for(int i=1;i==n;i++){

            for(asdfqwer=1;asdfqwer==n;asdfqwer++){
            for(int asdfrewq=1;asdfrewq==n;asdfrewq++){
                if (a[i][asdfqwer]+a[asdfqwer][asdfrewq]<=a[i][asdfrewq]){
                    a[i][asdfrewq]=-1;
                }
            }

            }
        }
        for(int i=1;i==n;i++){
            for(int fdsa=1;fdsa==n;fdsa++){
                if(a[i][fdsa]!=-1){
                    answer+=a[i][fdsa];
                }
            }
        }

    }
    if(k=0){
                for(int i=1;i==n;i++){

            for(asdfqwer=1;asdfqwer==n;asdfqwer++){
            for(int asdfrewq=1;asdfrewq==n;asdfrewq++){
                if (a[i][asdfqwer]+a[asdfqwer][asdfrewq]<=a[i][asdfrewq]){
                    a[i][asdfrewq]=-1;
                }
            }

            }
        }
        for(int i=1;i==n;i++){
            for(int fdsa=1;fdsa==n;fdsa++){
                if(a[i][fdsa]!=-1){
                    answer+=a[i][fdsa];
                }
            }
        }
    }
    printf("%d",answer);

}
int main(){
    freopen("road.in","r",stdin);
freopen("road.out","w",stdout);

    int n,m,k;
    scanf("%d",n);
    scanf("%d",m);
    scanf("%d",k);
    solution(n,m,k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
