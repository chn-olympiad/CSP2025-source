#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
struct node{
    int a1,a2,a3;
}cl[100050];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(cl,0,sizeof(cl));
        priority_queue<PII,vector<PII>,greater<PII> > a,b,c;
        int aa=0,bb=0,cc=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>cl[i].a1>>cl[i].a2>>cl[i].a3;
            if(cl[i].a1>=cl[i].a2&&cl[i].a1>=cl[i].a3){
                if(aa<n/2){
                    a.push(make_pair(cl[i].a1,i));
                    aa++;
                }
                else if(cl[i].a1<a.top().first){
                    if(cl[i].a2>=cl[i].a3){
                        b.push(make_pair(cl[i].a2,i));
                        bb++;
                    }
                    else{
                        c.push(make_pair(cl[i].a3,i));
                        cc++;
                    }
                }
                else if(cl[i].a1==a.top().first){
                    int s1=cl[i].a2,s2=cl[i].a3,s3=cl[a.top().second].a2,s4=cl[a.top().second].a3;
                    if(s1>=s2&&s1>=s3&&s1>=s4){
                        b.push(make_pair(s1,i));
                        bb++;
                    }
                    else if(s2>=s1&&s2>=s3&&s2>=s4){
						c.push(make_pair(s2,i));
						cc++;
					}
					else if(s3>=s1&&s3>=s2&&s3>=s4){
						b.push(make_pair(s3,a.top().second));
						a.pop();
						a.push(make_pair(cl[i].a1,i));
						bb++;
					}
					else{
                        c.push(make_pair(s4,a.top().second));
						a.pop();
						a.push(make_pair(cl[i].a1,i));
						cc++;
					}
                }
                else{
                    a.push(make_pair(cl[i].a1,i));
                    int o1=cl[a.top().second].a2,o2=cl[a.top().second].a3;
                    if(o1>=o2){
                        b.push(make_pair(o1,a.top().second));
                    }
                    else{
                        c.push(make_pair(o2,a.top().second));
                    }
                    a.pop();
                }
            }
            else if(cl[i].a2>=cl[i].a1&&cl[i].a2>=cl[i].a3){
                if(bb<n/2){
                    b.push(make_pair(cl[i].a2,i));
                    bb++;
                }
                else if(cl[i].a2<b.top().first){
                    if(cl[i].a1>=cl[i].a3){
                        a.push(make_pair(cl[i].a1,i));
                        aa++;
                    }
                    else{
                        c.push(make_pair(cl[i].a3,i));
                        cc++;
                    }
                }
                else if(cl[i].a2==b.top().first){
                    int s1=cl[i].a1,s2=cl[i].a3,s3=cl[a.top().second].a1,s4=cl[a.top().second].a3;
                    if(s1>=s2&&s1>=s3&&s1>=s4){
                        a.push(make_pair(s1,i));
                        aa++;
                    }
                    else if(s2>=s1&&s2>=s3&&s2>=s4){
						c.push(make_pair(s2,i));
						cc++;
					}
					else if(s3>=s1&&s3>=s2&&s3>=s4){
						a.push(make_pair(s3,a.top().second));
						b.pop();
						b.push(make_pair(cl[i].a2,i));
						aa++;
					}
					else{
                        c.push(make_pair(s4,a.top().second));
						b.pop();
						b.push(make_pair(cl[i].a2,i));
						cc++;
					}
                }
                else{
                    b.push(make_pair(cl[i].a2,i));
                    int o1=cl[b.top().second].a1,o2=cl[b.top().second].a3;
                    if(o1>=o2){
                        a.push(make_pair(o1,b.top().second));
                    }
                    else{
                        c.push(make_pair(o2,b.top().second));
                    }
                    b.pop();
                }
            }
            else{
                if(cc<n/2){
                    c.push(make_pair(cl[i].a3,i));
                    cc++;
                }
                else if(cl[i].a3<a.top().first){
                    if(cl[i].a2>=cl[i].a1){
                        b.push(make_pair(cl[i].a2,i));
                        bb++;
                    }
                    else{
                        a.push(make_pair(cl[i].a3,i));
                        aa++;
                    }
                }
                else if(cl[i].a3==c.top().first){
                    int s1=cl[i].a2,s2=cl[i].a1,s3=cl[a.top().second].a2,s4=cl[a.top().second].a1;
                    if(s1>=s2&&s1>=s3&&s1>=s4){
                        b.push(make_pair(s1,i));
                        bb++;
                    }
                    else if(s2>=s1&&s2>=s3&&s2>=s4){
						a.push(make_pair(s2,i));
						aa++;
					}
					else if(s3>=s1&&s3>=s2&&s3>=s4){
						b.push(make_pair(s3,a.top().second));
						c.pop();
						c.push(make_pair(cl[i].a1,i));
						bb++;
					}
					else{
                        a.push(make_pair(s4,a.top().second));
						c.pop();
						c.push(make_pair(cl[i].a1,i));
						aa++;
					}
                }
                else{
                    c.push(make_pair(cl[i].a3,i));
                    int o1=cl[a.top().second].a2,o2=cl[a.top().second].a1;
                    if(o1>=o2){
                        b.push(make_pair(o1,c.top().second));
                    }
                    else{
                        a.push(make_pair(o2,c.top().second));
                    }
                    c.pop();
                }
            }
        }
        int num=0;
        while(!a.empty()){
            num+=(a.top().first);
            a.pop();
        }
        while(!b.empty()){
            num+=(b.top().first);
            b.pop();
        }
        while(!c.empty()){
            num+=(c.top().first);
            c.pop();
        }
        cout<<num;
    }
    return 0;
}
