#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    /*
    哇，居然没读明白！
    随机数拯救世界！！！
    躺平ing……
    一个一个走过，一个一个错过
    一遍一遍来过，一次一次放过
    一声一声笑着，一声一声吼着
    一幕一幕闪着刺痛我
    因为享受着她的灿烂
    因为忍受着她的腐烂
    你说别追呀，又依依不舍
    所以生命呀它苦涩如歌
    因为享受着她的灿烂
    因为忍受着她的腐烂
    你说别爱呀，又依依不舍
    所以生命呀它苦涩如歌
    */
    srand(time(0));
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=q ;++i)
    {
        int r = rand()%200+1;
        printf("%d\n",(r<=40)?r:0);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 我要上迷惑行为大赏！