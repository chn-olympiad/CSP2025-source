#include<bits/stdc++.h>
using namespace std;

int shu,num[5200],ans=0;
vector<int> ty;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);


    cin>>shu;

    for(int f=1;f<=shu;f++){
        cin>>num[f];
    }

    if(shu==3){

        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    ty.clear();
                    if(i1==1){
                        ty.push_back(num[1]);
                    }if(i2==1){
                        ty.push_back(num[2]);
                    }if(i3==1){
                        ty.push_back(num[3]);}
                    if(ty.size()<3)break;
                    int big=0,zong=0;
                    for(int z:ty){
                        zong+=z;
                        if(z>big)big=z;
                    }
                    if(zong>big*2)ans++;
                }
            }
        }
    }

    if(shu==4){

        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){

                        ty.clear();
                        if(i1==1){
                            ty.push_back(num[1]);
                        }if(i2==1){
                            ty.push_back(num[2]);
                        }if(i3==1){
                            ty.push_back(num[3]);}
                        if(i4==1){
                            ty.push_back(num[4]);}
                        if(ty.size()<3)break;
                        int big=0,zong=0;
                        for(int z:ty){
                            zong+=z;
                            if(z>big)big=z;
                        }
                        if(zong>big*2)ans++;
                    }
                }
            }
        }
    }
if(shu==5){
        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                        ty.clear();
                        if(i1==1){
                            ty.push_back(num[1]);
                        }if(i2==1){
                            ty.push_back(num[2]);
                        }if(i3==1){
                            ty.push_back(num[3]);}
                        if(i4==1){
                            ty.push_back(num[4]);}
                        if(i5==1){
                            ty.push_back(num[5]);}
                        if(ty.size()<3)break;
                        int big=0,zong=0;
                        for(int z:ty){
                            zong+=z;
                            if(z>big)big=z;
                        }
                        if(zong>big*2)ans++;
                        }
                    }
                }
            }
        }
    }
    if(shu==6){
        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                            for(int i6=1;i6<=2;i6++){
                        ty.clear();
                        if(i1==1){
                            ty.push_back(num[1]);
                        }if(i2==1){
                            ty.push_back(num[2]);
                        }if(i3==1){
                            ty.push_back(num[3]);}
                        if(i4==1){
                            ty.push_back(num[4]);}
                        if(i5==1){
                            ty.push_back(num[5]);}
                        if(i6==1){
                            ty.push_back(num[6]);}
                        if(ty.size()<3)break;
                        int big=0,zong=0;
                        for(int z:ty){
                            zong+=z;
                            if(z>big)big=z;
                        }
                        if(zong>big*2)ans++;
                        }
                        }
                    }
                }
            }
        }
    }
    if(shu==7){
        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                            for(int i6=1;i6<=2;i6++){
                                for(int i7=1;i7<=2;i7++){

                                    ty.clear();
                                    if(i1==1){
                                        ty.push_back(num[1]);
                                    }if(i2==1){
                                        ty.push_back(num[2]);
                                    }if(i3==1){
                                        ty.push_back(num[3]);}
                                    if(i4==1){
                                        ty.push_back(num[4]);}
                                    if(i5==1){
                                        ty.push_back(num[5]);}
                                    if(i6==1){
                                        ty.push_back(num[6]);}
                                    if(i7==1){
                                        ty.push_back(num[7]);}
                                    if(ty.size()<3)break;
                                    int big=0,zong=0;
                                    for(int z:ty){
                                        zong+=z;
                                        if(z>big)big=z;
                                    }
                                    if(zong>big*2)ans++;
                                    }
                        }
                        }
                    }
                }
            }
        }
    }
if(shu==8){
        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                            for(int i6=1;i6<=2;i6++){
                                for(int i7=1;i7<=2;i7++){
                                    for(int i8=1;i8<=2;i8++){
                                    ty.clear();
                                    if(i1==1){
                                        ty.push_back(num[1]);
                                    }if(i2==1){
                                        ty.push_back(num[2]);
                                    }if(i3==1){
                                        ty.push_back(num[3]);}
                                    if(i4==1){
                                        ty.push_back(num[4]);}
                                    if(i5==1){
                                        ty.push_back(num[5]);}
                                    if(i6==1){
                                        ty.push_back(num[6]);}
                                    if(i7==1){
                                        ty.push_back(num[7]);}
                                    if(i8==1){
                                        ty.push_back(num[8]);}
                                    if(ty.size()<3)break;
                                    int big=0,zong=0;
                                    for(int z:ty){
                                        zong+=z;
                                        if(z>big)big=z;
                                    }
                                    if(zong>big*2)ans++;
                                }
                                    }
                            }
                        }
                    }
                }
            }
        }
    }
 if(shu==9){
        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                            for(int i6=1;i6<=2;i6++){
                                for(int i7=1;i7<=2;i7++){
                                    for(int i8=1;i8<=2;i8++){
                                        for(int i9=1;i9<=2;i9++){
                                    ty.clear();
                                    if(i1==1){
                                        ty.push_back(num[1]);
                                    }if(i2==1){
                                        ty.push_back(num[2]);
                                    }if(i3==1){
                                        ty.push_back(num[3]);}
                                    if(i4==1){
                                        ty.push_back(num[4]);}
                                    if(i5==1){
                                        ty.push_back(num[5]);}
                                    if(i6==1){
                                        ty.push_back(num[6]);}
                                    if(i7==1){
                                        ty.push_back(num[7]);}
                                    if(i8==1){
                                        ty.push_back(num[8]);}
                                    if(i9==1){
                                        ty.push_back(num[9]);}
                                    if(ty.size()<3)break;
                                    int big=0,zong=0;
                                    for(int z:ty){
                                        zong+=z;
                                        if(z>big)big=z;
                                    }
                                    if(zong>big*2)ans++;
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
    if(shu==10){

        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                            for(int i6=1;i6<=2;i6++){
                                for(int i7=1;i7<=2;i7++){
                                    for(int i8=1;i8<=2;i8++){
                                        for(int i9=1;i9<=2;i9++){
                                            for(int i10=1;i10<=2;i10++){
                                                ty.clear();
                                                if(i1==1){
                                                    ty.push_back(num[1]);
                                                }if(i2==1){
                                                    ty.push_back(num[2]);
                                                }if(i3==1){
                                                    ty.push_back(num[3]);}
                                                if(i4==1){
                                                    ty.push_back(num[4]);}
                                                if(i5==1){
                                                    ty.push_back(num[5]);}
                                                if(i6==1){
                                                    ty.push_back(num[6]);}
                                                if(i7==1){
                                                    ty.push_back(num[7]);}
                                                if(i8==1){
                                                    ty.push_back(num[8]);}
                                                if(i9==1){
                                                    ty.push_back(num[9]);}
                                                if(i10==1){
                                                    ty.push_back(num[10]);}
                                                if(ty.size()<3)break;
                                                int big=0,zong=0;
                                                for(int z:ty){
                                                    zong+=z;
                                                    if(z>big)big=z;
                                                }
                                                if(zong>big*2)ans++;
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
    if(shu==20){
        for(int i1=1;i1<=2;i1++){
            for(int i2=1;i2<=2;i2++){
                for(int i3=1;i3<=2;i3++){
                    for(int i4=1;i4<=2;i4++){
                        for(int i5=1;i5<=2;i5++){
                            for(int i6=1;i6<=2;i6++){
                                for(int i7=1;i7<=2;i7++){
                                    for(int i8=1;i8<=2;i8++){
                                        for(int i9=1;i9<=2;i9++){
                                            for(int i10=1;i10<=2;i10++){
                                                for(int i11=1;i11<=2;i11++){
                                                    for(int i12=1;i12<=2;i12++){
                                                        for(int i13=1;i13<=2;i13++){
                                                            for(int i14=1;i14<=2;i14++){
                                                                for(int i15=1;i15<=2;i15++){
                                                                    for(int i16=1;i16<=2;i16++){
                                                                        for(int i17=1;i17<=2;i17++){
                                                                            for(int i18=1;i18<=2;i18++){
                                                                                for(int i19=1;i19<=2;i19++){
                                                                                    for(int i20=1;i20<=2;i20++){
                                                ty.clear();
                                                if(i1==1){
                                                    ty.push_back(num[1]);
                                                }if(i2==1){
                                                    ty.push_back(num[2]);
                                                }if(i3==1){
                                                    ty.push_back(num[3]);}
                                                if(i4==1){
                                                    ty.push_back(num[4]);}
                                                if(i5==1){
                                                    ty.push_back(num[5]);}
                                                if(i6==1){
                                                    ty.push_back(num[6]);}
                                                if(i7==1){
                                                    ty.push_back(num[7]);}
                                                if(i8==1){
                                                    ty.push_back(num[8]);}
                                                if(i9==1){
                                                    ty.push_back(num[9]);}
                                                if(i10==1){
                                                    ty.push_back(num[10]);}
                                                if(i11==1){
                                                    ty.push_back(num[11]);}
                                                    if(i12==1){
                                                    ty.push_back(num[12]);}
                                                    if(i13==1){
                                                    ty.push_back(num[13]);}
                                                    if(i14==1){
                                                    ty.push_back(num[14]);}
                                                    if(i15==1){
                                                    ty.push_back(num[15]);}
                                                    if(i16==1){
                                                    ty.push_back(num[16]);}
                                                    if(i17==1){
                                                    ty.push_back(num[17]);}
                                                    if(i18==1){
                                                    ty.push_back(num[18]);}
                                                    if(i19==1){
                                                    ty.push_back(num[19]);}
                                                    if(i20==1){
                                                    ty.push_back(num[20]);}
                                                if(ty.size()<3)break;
                                                int big=0,zong=0;
                                                for(int z:ty){
                                                    zong+=z;
                                                    if(z>big)big=z;
                                                }
                                                if(zong>big*2)ans++;
                                                                    }}}}}}}}}}
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
    cout<<ans;


    return 0;
}
