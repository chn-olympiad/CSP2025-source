#include<bits/stdc++.h>
using namespace std;
int T,n;
struct xue{
    int a1;
    int a2;
    int a3;
    int maxx;
    int cida;
    int cha;
    int xuan;
}f[100000];
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>T;
    while(T--){
        cin>>n;
        int da1=0,da2=0,da3=0,ans=0;
        for(int i=1;i<=n;i++){
            cin>>f[i].a1>>f[i].a2>>f[i].a3;//输入
            f[i].maxx=max(f[i].a1,max(f[i].a2,f[i].a3));//计算最大值
            int minn=min(f[i].a1,min(f[i].a2,f[i].a3));
            f[i].cida=f[i].a1+f[i].a2+f[i].a3-f[i].maxx-minn;//计算次大值
            f[i].cha=f[i].maxx-f[i].cida;
            if(f[i].maxx==f[i].a1){//如果更喜欢第一个
                if(da1<n/2){//人还够
                    f[i].xuan=1;//我去1社团
                    da1++;//进去
                    ans+=f[i].maxx;//累加答案
                }
                else{
                    int dangcha=f[i].cha;//当前最大和次大的差值
                    int minn_cha=0x3f3f3f3f,id;
                    for(int j=i-1;j>=1;j--){
                        if(f[j].xuan==1&&minn_cha>f[j].cha){//目标
                            id=j;//记录一下位置
                            minn_cha=f[j].cha;//改变最da值
                        }
                    }
                    if(dangcha<minn_cha){//如果他的差值最da那就委屈一下他
                        if(f[i].cida==f[i].a2){//a2是次大
                            da2++;
                            ans+=f[i].a2;
                            f[i].xuan=2;//我选2
                        }
                        else{
                            da3++;
                            ans+=f[i].a3;
                            f[i].xuan=3;//我选3
                        }
                    }
                    else{//委屈一下别人吧；
                        ans+=f[i].a1-f[id].maxx+f[id].cida;//调！
                        f[i].xuan=1;
                        if(f[id].cida==f[id].a2){//被调的次大为a2
                            f[id].xuan=2;
                            da2++;
                        }
                        else{
                            f[id].xuan=3;
                            da3++;
                        }
                    }
                }
            }
            /////////
            else if(f[i].maxx==f[i].a2){//如果更喜欢第2个
                if(da2<n/2){//人还够
                    f[i].xuan=2;//我去2社团
                    da2++;//进去
                    ans+=f[i].maxx;//累加答案
                }
                else{
                    int dangcha=f[i].cha;//当前最大和次大的差值
                    int minn_cha=0x3f3f3f3f,id;
                    for(int j=i-1;j>=1;j--){
                        if(f[j].xuan==2&&minn_cha>f[j].cha){//目标
                            id=j;//记录一下位置
                            minn_cha=f[j].cha;//改变最da值
                        }
                    }
                    if(dangcha<minn_cha){//如果他的差值最小那就委屈一下他
                        if(f[i].cida==f[i].a1){//a2是次大
                            da1++;
                            ans+=f[i].a1;
                            f[i].xuan=1;//我选1
                        }
                        else{
                            da3++;
                            ans+=f[i].a3;
                            f[i].xuan=3;//我选3
                        }
                    }
                    else{//委屈一下别人吧；
                        ans+=f[i].a2-f[id].maxx+f[id].cida;//调！
                        f[i].xuan=2;
                        if(f[id].cida==f[id].a1){//被调的次大为1
                            f[id].xuan=1;
                            da1++;
                        }
                        else{
                            f[id].xuan=3;
                            da3++;
                        }
                    }
                }
            }
            //////////
            else{//如果更喜欢第3个
                if(da3<n/2){//人还够
                    f[i].xuan=3;//我去3社团
                    da3++;//进去
                    ans+=f[i].maxx;//累加答案
                }
                else{
                    int dangcha=f[i].cha;//当前最大和次大的差值
                    int minn_cha=0x3f3f3f3f,id;
                    for(int j=i-1;j>=1;j--){
                        if(f[j].xuan==3&&minn_cha>f[j].cha){//目标
                            id=j;//记录一下位置
                            minn_cha=f[j].cha;//改变最da值
                        }
                    }
                    if(dangcha<minn_cha){//如果他的差值最小那就委屈一下他
                        if(f[i].cida==f[i].a2){//a2是次大
                            da2++;
                            ans+=f[i].a2;
                            f[i].xuan=2;//我选2
                        }
                        else{
                            da1++;
                            ans+=f[i].a1;
                            f[i].xuan=1;//我选1
                        }
                    }
                    else{//委屈一下别人吧；
                        ans+=f[i].a3-f[id].maxx+f[id].cida;//调！
                        f[i].xuan=3;
                        if(f[id].cida==f[id].a1){//被调的次大为a1
                            f[id].xuan=1;
                            da1++;
                        }
                        else{
                            f[id].xuan=2;
                            da2++;
                        }
                    }
                }
            }


        }
        cout<<ans<<endl;
    }
    return 0;
}//感慨一下：这道题整整花了我2个小时，纠了不下20个错！！！！！！啊啊啊啊啊啊啊啊啊啊！
