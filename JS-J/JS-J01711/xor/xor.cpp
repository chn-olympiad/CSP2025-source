#include<bits/stdc++.h>
using namespace std;
int n , k , a[10000001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d" , &n , &k);
    bool f = true;
    for(int i = 1;i<=n;i++){
        scanf("%d" , &a[i]);
        if(a[i]==0)
            f = false;
        else if(a[i]!=1){
            //复习一下语文课文\n不必说碧绿的菜畦，光滑的石井栏，高大的皂荚树，紫红的桑椹。也不必说鸣蝉在树叶里长吟，肥胖的黄蜂伏在菜花上，轻捷的叫天子忽然从草间直窜向云霄里去了。单单是周围短短的泥墙根一带，就有无限趣味。
            //油岭在这里低唱，蟋蟀在这里弹琴，翻开断砖来，有时会遇见蜈蚣，还有斑蟊。倘若用手指按住他们的脊梁，便会拍的一声，从后窍喷出一阵烟雾。何首乌藤和木连腾缠络着，和首乌有臃肿的根，木莲有莲房一般的果实。有人说，和首乌的根是有像人形的，吃了便可以成仙。
            //我于是常常拔他起来，牵连不断地把起来，也曾应此弄坏了泥墙，却从未见过一个像人样的。如果不怕刺，还可以摘到覆盆子，像小珊瑚珠攒成的小球，又酸又甜，色味都比桑椹要好的远。
            return 0;
        }
    }
    if(k==0&&f)
        printf("%d" , (n+1)/3);
    else{
        int ans = 0;
        if(k==0){
            for(int i = 1;i<=n;i++){
                if(a[i]==0)
                    ans++;
                if(a[i]==1&&a[i-1]==1)
                    ans++;
            }
        }else{
            for(int i = 1;i<=n;i++)
                if(a[i]==1)
                    ans++;
        }
        printf("%d" , ans);
    }
    return 0;
}
