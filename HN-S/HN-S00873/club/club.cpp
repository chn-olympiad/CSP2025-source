#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,p1[100005],p2[100005],p3[100005],o[100005],x=1,y=1,z=1,an1,an2,an3;
struct s{
    int a;
    int b;
    int c;
}du[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int j=1;j<=t;j++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>du[i].a>>du[i].b>>du[i].c;
            if(du[i].a>du[i].b and du[i].a>du[i].c){
                if(x<=(n/2)){
                    p1[x]=du[i].a;
                    an1+=p1[x];
                    x++;
                    sort(p1+1,p1+x);
                }
                else{
                    if(du[i].a>p1[1]){
                        an1+=du[i].a;
                        an1-=p1[1];
                        p1[1]=du[i].a;

                        sort(p1+1,p1+x);
                    }
                }
            }
            else if(du[i].b>du[i].c and du[i].b>du[i].a){
                if(y<=(n/2)){
                    p2[y]=du[i].b;
                    an2+=p2[y];
                    y++;
                    sort(p2+1,p2+y);
                }
                else{
                    if(du[i].b>p2[1]){
                        an2+=du[i].b;
                        an2-=p2[1];
                        p2[1]=du[i].b;

                        sort(p2+1,p2+y);
                    }
                }
            }
            else if(du[i].c>du[i].b and du[i].c>du[i].a){
                if(z<=(n/2)){
                    p3[z]=du[i].c;
                    an3+=p3[z];
                    z++;
                    sort(p3+1,p3+z);
                }
                else{
                    if(du[i].c>p3[1]){
                        an3+=du[i].c;
                        an3-=p3[1];
                        p3[1]=du[i].c;

                        sort(p3+1,p3+z);
                    }


                }
            }
            else if(du[i].a==du[i].b){
                if(x>n/2 and y>n/2){
                    if(p2[1]>p1[1]){
                        if(du[i].a>p1[1]){
                            an1+=du[i].a;
                            an1-=p1[1];
                            p1[1]=du[i].a;

                            sort(p1+1,p1+x);
                        }
                        else if(du[i].b>p2[1]){
                            an2+=du[i].b;
                            an2-=p2[1];
                            p2[1]=du[i].b;

                            sort(p2+1,p2+y);
                        }
                    }
                    else{
                        if(du[i].b>p2[1]){
                            an2+=du[i].b;
                            an2-=p2[1];
                            p2[1]=du[i].b;

                            sort(p2+1,p2+y);
                        }

                        else if(du[i].a>p1[1]){
                            an1+=du[i].a;
                            an1-=p1[1];
                            p1[1]=du[i].a;

                            sort(p1+1,p1+x);
                        }
                    }
                }
                else if(x<y){
                    an1+=p1[x];
                    p1[x]=du[i].a;
                    x++;
                    sort(p1+1,p1+x);
                }
                else if(y<x){
                    an2+=p2[y];
                    p2[y]=du[i].b;
                    y++;
                    sort(p2+1,p2+y);
                }
                else if(x==y){
                    if(an1>an2){
                        an2+=p2[y];
                        p2[y]=du[i].b;
                        y++;
                        sort(p2+1,p2+y);
                    }
                    else{
                        an1+=p1[x];
                        p1[x]=du[i].a;
                        x++;
                        sort(p1+1,p1+x);
                    }
                }

            }
            else if(du[i].a==du[i].c){
                if(x>n/2 and z>n/2){
                    if(p3[1]>p1[1]){
                        if(du[i].a>p1[1]){
                            an1+=du[i].a;
                            an1-=p1[1];
                            p1[1]=du[i].a;

                            sort(p1+1,p1+x);
                        }
                        else if(du[i].c>p3[1]){
                            an3+=du[i].c;
                            an3-=p3[1];
                            p3[1]=du[i].c;

                            sort(p3+1,p3+z);
                        }
                    }
                    else{
                        if(du[i].c>p3[1]){
                            an3+=du[i].c;
                            an3-=p3[1];
                            p3[1]=du[i].c;

                            sort(p3+1,p3+z);
                        }
                        else if(du[i].a>p1[1]){
                            an1+=du[i].a;
                            an1-=p1[1];
                            p1[1]=du[i].a;

                            sort(p1+1,p1+x);
                        }
                    }
                }
                else if(x<z){
                    an1+=p1[x];
                    p1[x]=du[i].a;
                    x++;
                    sort(p1+1,p1+x);
                }
                else if(z<x){
                    an3+=p3[z];
                    p3[z]=du[i].c;
                    z++;
                    sort(p3+1,p3+z);
                }
                else if(x==y){
                    if(an1>an2){
                        an3+=p3[z];
                        p3[z]=du[i].c;
                        z++;
                        sort(p3+1,p3+z);
                    }
                    else{
                        an1+=p1[x];
                        p1[x]=du[i].a;
                        x++;
                        sort(p1+1,p1+x);
                    }
                }

            }
            else if(du[i].c==du[i].b){
                if(z>n/2 and b>n/2){
                    if(p2[1]>p3[1]){
                        if(du[i].c>p3[1]){
                            an3+=du[i].c;
                            an3-=p3[1];
                            p3[1]=du[i].c;

                            sort(p3+1,p3+z);
                        }
                        else if(du[i].b>p2[1]){
                            an2+=du[i].b;
                            an2-=p2[1];
                            p2[1]=du[i].b;

                            sort(p2+1,p2+y);
                        }
                    }
                    else{
                        if(du[i].b>p2[1]){
                            an2+=du[i].b;
                            an2-=p2[1];
                            p2[1]=du[i].b;

                            sort(p2+1,p2+y);
                        }
                        else if(du[i].c>p3[1]){
                            an3+=du[i].c;
                            an3-=p3[1];
                            p3[1]=du[i].c;

                            sort(p3+1,p3+z);
                        }
                    }
                }
                else if(z<y){
                    an3+=p3[z];
                    p3[z]=du[i].c;
                    z++;
                    sort(p3+1,p3+z);
                }
                else if(y<z){
                    an2+=p2[y];
                    p2[y]=du[i].b;
                    y++;
                    sort(p2+1,p2+y);
                }
                else if(z==y){
                    if(an3>an2){
                        an2+=p2[y];
                        p2[y]=du[i].b;
                        y++;
                        sort(p2+1,p2+y);
                    }
                    else{
                        an3+=p3[z];
                        p3[z]=du[i].c;
                        z++;
                        sort(p3+1,p3+z);
                    }
                }

            }
            cout<<an1+an2+an3<<endl;
            an1=0;
            an2=0;
            an3=0;
        }





    }
    return 0;
}
