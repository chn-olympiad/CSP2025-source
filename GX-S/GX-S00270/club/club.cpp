#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long a;
    cin>>a;
    for(int i=0;i<a;i++){
        int t=0;
        cin>>t;
        if(t==2){
            int p1,p2,p3,p4,p5,p6;
            cin>>p1>>p2>>p3>>p4>>p5>>p6;
            cout<<max(p1+p5,max(p1+p6,max(p2+p6,max(p2+p4,max(p3+p4,p3+p5)))))<<endl;
        }else if(t==4){
            int ll[12]={0};
            for(int ii=1;ii<=12;ii++){
                cin>>ll[ii];
            }
            long long d=0;
            for(int i1=1;i1<=3;i1++){
                    for(int j=1;j<=3;j++){
                        for(int k=1;k<=3;k++){
                            for(int ss=1;ss<=3;ss++){
                                    int y=0,e=0,s=0;
                                if(i1==1){
                                    y++;
                                }
                                if(j==1){
                                    y++;
                                }
                                if(k==1){
                                    y++;
                                }
                                if(ss==1){
                                    y++;
                                }
                                if(i1==2){
                                    e++;
                                }
                                if(j==2){
                                    e++;
                                }
                                if(k==2){
                                    e++;
                                }
                                if(ss==2){
                                    e++;
                                }

                                if(i1==3){
                                    s++;
                                }
                                if(j==3){
                                    s++;
                                }
                                if(k==3){
                                    s++;
                                }
                                if(ss==3){
                                    s++;
                                }
                                if(y<=2&&e<=2&&s<=2){
                                    if((ll[i1]+ll[j+3]+ll[k+6]+ll[ss+9])>d){
                                        d=ll[i1]+ll[j+3]+ll[k+6]+ll[ss+9];
                                    }
                                }
                        }
                    }
            }
            }
            cout<<d<<endl;
        }


        else if(t==10){
            int ll[30]={0};
            for(int ii=1;ii<=30;ii++){
                cin>>ll[ii];
            }
            long long d=0;
            for(int i1=1;i1<=3;i1++){
               for(int i2=1;i2<=3;i2++){
                    for(int i3=1;i3<=3;i3++){
                    for(int i4=1;i4<=3;i4++){
                    for(int i5=1;i5<=3;i5++){
                    for(int i6=1;i6<=3;i6++){
                    for(int i7=1;i7<=3;i7++){
                    for(int i8=1;i8<=3;i8++){
                    for(int i9=1;i9<=3;i9++){
                    for(int i10=1;i10<=3;i10++){
                            int y=0,e=0,s=0;
                    if(i1==1){
                        y++;
                    }
                    if(i2==1){
                        y++;
                    }
                    if(i3==1){
                        y++;
                    }
                    if(i4==1){
                        y++;
                    }
                    if(i5==1){
                        y++;
                    }
                    if(i6==1){
                        y++;
                    }
                    if(i7==1){
                        y++;
                    }
                    if(i8==1){
                        y++;
                    }
                    if(i9==1){
                        y++;
                    }
                    if(i10==1){
                        y++;
                    }
                    if(i1==2){
                        e++;
                    }
                    if(i10==2){
                        e++;
                    }
                    if(i2==2){
                        e++;
                    }
                    if(i3==2){
                        e++;
                    }
                    if(i4==2){
                        e++;
                    }
                    if(i5==2){
                        e++;
                    }
                    if(i6==2){
                        e++;
                    }
                    if(i7==2){
                        e++;
                    }
                    if(i8==2){
                        e++;
                    }
                    if(i9==2){
                        e++;
                    }

                    if(i1==3){
                        s++;
                    }
                    if(i2==3){
                        s++;
                    }
                    if(i3==3){
                        s++;
                    }
                    if(i4==3){
                        s++;
                    }
                    if(i5==3){
                        s++;
                    }
                    if(i6==3){
                        s++;
                    }
                    if(i7==3){
                        s++;
                    }
                    if(i8==3){
                        s++;
                    }
                    if(i9==3){
                        s++;
                    }
                    if(i10==3){
                        s++;
                    }


                    if(y<=5&&e<=5&&s<=5){
                        if(ll[i1]+ll[i2+3]+ll[i3+6]+ll[i4+9]+ll[i5+12]+ll[i6+15]+ll[i7+18]+ll[i8+21]+ll[i9+24]+ll[i10+27]>d){
                            d=ll[i1]+ll[i2+3]+ll[i3+6]+ll[i4+9]+ll[i5+12]+ll[i6+15]+ll[i7+18]+ll[i8+21]+ll[i9+24]+ll[i10+27];
                        }
                    }

        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        cout<<d<<endl;
    }


    }
    return 0;
}
