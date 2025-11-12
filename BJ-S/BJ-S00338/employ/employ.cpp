#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5];
int v1i,v2i,v3i,v1max,v2max,v3max,v1lessmax,v2lessmax,v3lessmax;
int v1,v2,v3,num1,num2,num3;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n;
        v1=0;v2=0;v3=0;
        v1i=0;v2i=0;v3i=0;
        num1=0;num2=0;num3=0;
        v1max=0;v2max=0;v3max=0;
        v1lessmax=0;v2lessmax=0;v3lessmax=0;
        for(int i=0;i<n;i++){
            int flag=0;
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]){
                v1+=a[i][1];
                num1++;
                if(num1>n/2){
                    cout<<a[v1i][v1max]<<" "<<a[i][2]<<" "<<a[v1i][v1lessmax]<<" "<<a[i][1]<<endl;
                    if(a[v1i][v1max]+a[i][2]>=a[v1i][v1lessmax]+a[i][1]){
                        cout<<a[v1i][v1max]<<" "<<a[i][2]<<" "<<a[v1i][v1lessmax]<<" "<<a[i][1]<<endl;
                        v1-=a[i][1];
                        num1--;
                        a[i][1]=-1;
                        v2+=a[i][2];
                        num2++;
                        if(num2>n/2){
                            v2-=a[i][2];
                            num2--;
                            v3+=a[i][3];
                            num3++;
                        }
                        if(a[i][2]+a[i][3]<a[v2i][v2max]+a[v2i][v2lessmax]){
                            v2i=i;
                            v2max=2;
                            v2lessmax=3;
                            flag=1;
                        }
                    }
                    if(!flag){
                        if(a[i][1]+a[i][2]<a[v1i][v1max]+a[v1i][v1lessmax]||(v1i==0&&v1max==0&&v1lessmax==0)){
                            v1i=i;
                            v1max=1;
                            v1lessmax=2;
                            cout<<"!!!"<<endl;
                        }
                    }
                }
                cout<<"1>=2>=3"<<endl;
                cout<<v1<<" "<<v2<<" "<<v3<<endl;
                cout<<"num"<<num1<<" "<<num2<<" "<<num3<<endl;
                continue;
            }else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]){
                v1+=a[i][1];
                num1++;
                if(num1>n/2){
                    if(a[v1i][v1max]+a[i][3]>=a[v1i][v1lessmax]+a[i][1]){
                        v1-=a[i][1];
                        num1--;
                        a[i][1]=-1;
                        v3+=a[i][3];
                        num3++;
                        if(num3>n/2){
                            v3-=a[i][3];
                            num3--;
                            v2+=a[i][2];
                            num2++;
                        }
                        if(a[i][3]+a[i][2]<a[v3i][v3max]+a[v3i][v3lessmax]){
                            v3i=i;
                            v3max=3;
                            v3lessmax=2;
                            flag=1;
                        }
                    }
                    if(!flag){
                        if(a[i][1]+a[i][3]<a[v1i][v1max]+a[v1i][v1lessmax]||(v1i==0&&v1max==0&&v1lessmax==0)){
                            v1i=i;
                            v1max=1;
                            v1lessmax=3;
                        }
                    }
                }
                cout<<"1>=3>=2"<<endl;
                cout<<v1<<" "<<v2<<" "<<v3<<endl;
                cout<<"num"<<num1<<" "<<num2<<" "<<num3<<endl;
                continue;
            }else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){
                v2+=a[i][2];
                num2++;
                if(num2>n/2){
                    if(a[v2i][v2max]+a[i][1]>=a[v2i][v2lessmax]+a[i][2]){
                        v2-=a[i][2];
                        num2--;
                        a[i][2]=-1;
                        v1+=a[i][1];
                        num1++;
                        if(num1>n/2){
                            v1-=a[i][1];
                            num1--;
                            v3+=a[i][3];
                            num3++;
                        }
                        if(a[i][1]+a[i][3]<a[v1i][v1max]+a[v1i][v1lessmax]){
                            v1i=i;
                            v1max=1;
                            v1lessmax=3;
                            flag=1;
                        }
                    }
                    if(!flag){
                        if(a[i][2]+a[i][1]<a[v2i][v2max]+a[v2i][v2lessmax]||(v2i==0&&v2max==0&&v2lessmax==0)){
                            v2i=i;
                            v2max=2;
                            v2lessmax=1;
                        }
                    }
                }
                cout<<"2>=1>=3"<<endl;
                cout<<v1<<" "<<v2<<" "<<v3<<endl;
                continue;
            }else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]){
                v2+=a[i][2];
                num2++;
                if(num2>n/2){
                    if(a[v2i][v2max]+a[i][3]>=a[v2i][v2lessmax]+a[i][2]){
                        v2-=a[i][2];
                        num2--;
                        a[i][2]=-1;
                        v3+=a[i][3];
                        num3++;
                        if(num3>n/2){
                            v3-=a[i][3];
                            num3--;
                            v1+=a[i][1];
                            num1++;
                        }
                        if(a[i][3]+a[i][1]<a[v3i][v3max]+a[v3i][v3lessmax]){
                            v3i=i;
                            v3max=3;
                            v3lessmax=1;
                            flag=1;
                        }
                    }
                    if(!flag){
                        if(a[i][2]+a[i][3]<a[v2i][v2max]+a[v2i][v2lessmax]||(v2i==0&&v2max==0&&v2lessmax==0)){
                            v2i=i;
                            v2max=2;
                            v2lessmax=3;
                        }
                    }
                }
                cout<<"2>=3>=1"<<endl;
                cout<<v1<<" "<<v2<<" "<<v3<<endl;
                continue;
            }else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]){
                v3+=a[i][3];
                num3++;
                if(num3>n/2){
                    if(a[v3i][v3max]+a[i][1]>=a[v3i][v3lessmax]+a[i][3]){
                        v3-=a[i][3];
                        num3--;
                        a[i][3]=-1;
                        v1+=a[i][1];
                        num1++;
                        if(num1>n/2){
                            v1-=a[i][1];
                            num1--;
                            v2+=a[i][2];
                            num2++;
                        }
                        if(a[i][1]+a[i][2]<a[v1i][v1max]+a[v1i][v1lessmax]){
                            v1i=i;
                            v1max=1;
                            v1lessmax=2;
                            flag=1;
                        }
                    }
                    if(!flag){
                        if(a[i][3]+a[i][1]<a[v3i][v3max]+a[v3i][v3lessmax]||(v3i==0&&v3max==0&&v3lessmax==0)){
                            v3i=i;
                            v3max=3;
                            v3lessmax=3;
                        }
                    }
                }
                cout<<"3>=1>=2"<<endl;
                cout<<v1<<" "<<v2<<" "<<v3<<endl;
                continue;
            }else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]){
                v3+=a[i][3];
                num3++;
                if(num3>n/2){
                    if(a[v3i][v3max]+a[i][2]>=a[v3i][v3lessmax]+a[i][3]){
                        v3-=a[i][3];
                        num3--;
                        a[i][3]=-1;
                        v2+=a[i][2];
                        num2++;
                        if(num2>n/2){
                            v2-=a[i][2];
                            num2--;
                            v1+=a[i][1];
                            num1++;
                        }
                        if(a[i][2]+a[i][1]<a[v2i][v2max]+a[v2i][v2lessmax]){
                            v2i=i;
                            v2max=2;
                            v2lessmax=1;
                            flag=1;
                        }
                    }
                    if(!flag){
                        if(a[i][3]+a[i][2]<a[v3i][v3max]+a[v3i][v3lessmax]||(v3i==0&&v3max==0&&v3lessmax==0)){
                            v3i=i;
                            v3max=3;
                            v3lessmax=3;
                        }
                    }
                }
            }
            cout<<"3>=2>=1"<<endl;
            cout<<a[i][1]<<a[i][2]<<a[i][3]<<endl;
            cout<<v1<<" "<<v2<<" "<<v3<<endl;
            continue;
        }
        cout<<v1+v2+v3<<endl;
        cout<<v1<<" "<<v2<<" "<<v3<<endl;
    }
    return 0;
}