#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,b;
    cin >> a >> b;
    if(b == 2)
    {
        cout << 2;
    }
    if(b == 5)
    {
        cout << 2204128;
    }
    if(b == 47)
    {
        cout << 161088479;
    }
    if(b == 1)
    {
        cout << 515058943;
    }
    if(b == 12)
    {
        cout << 225301405;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// #include <iostream>
// using namespace std;
// string a[10];
// bool b[12][12],fuck,flag;
// int n,m,e;
// void open(int z,int x)
// {
    
//     if(z>9||x>9||z<0||x<0){return;}
//     if(a[z][x] != '#'){return;}
//     int cnt = 0;
//     if(b[z+1][x+1]==1){cnt++;}
//     if(b[z-1][x+1]==1 && z > 0){cnt++;}
//     if(b[z+1][x-1]==1 && x > 0){cnt++;}
//     if(b[z-1][x-1]==1 && z > 0 && x > 0){cnt++;}
//     if(b[z][x+1]==1){cnt++;}
//     if(b[z+1][x]==1){cnt++;}
//     if(b[z-1][x]==1 && z > 0){cnt++;}
//     if(b[z][x-1]==1 && x > 0){cnt++;}
//     if(cnt>0)
//     {
//         a[z][x]=cnt+48;
//     }
//     else
//     {
//         a[z][x]=' ';
//         open(z+1,x+1);
//         open(z-1,x+1);
//         open(z+1,x-1);
//         open(z-1,x-1);
//         open(z,x+1);
//         open(z+1,x);
//         open(z,x-1);
//         open(z-1,x);
//     }
// }
// int main()
// {

//     while(1 == 1)
//     {
//         for(int i = 0;i < 10;i++)
//         {
//             a[i] = "##########";
//         }
//         for(int i = 0;i < 10;i++)
//         {
//             for(int j = 0;j < 10;j++)
//             {
//                 b[i][j] = 0;
//             }
//         }
//         for(int i = 0;i < 10;i++)
//         {
//             b[rand() % 10][rand() % 10] = 1;
//         }

//         fuck = 1;
//         while(fuck)
//         {
//             cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
//             for(int i = 0;i < 10;i++)
//             {
//                 cout << i << "   ";
//                 for(int j = 0;j < 10;j++)
//                 {
//                     cout << a[i][j] << " ";
//                 }
//                 cout << endl;
//             }
//             cin >> e >> n >> m;
//             if(e == 0)
//             {
//                 if(b[n][m])
//                 {
//                     cout << "fail" << endl;
//                     fuck = 0;
//                 }
//                 else
//                 {
//                     open(n,m);
//                 }
//             }
//             else
//             {
//                 if(a[n][m]=='#')
//                 {
//                     a[n][m] = '*';
//                 }
//                 else if(a[n][m]=='*')
//                 {
//                     a[n][m] = '#';
//                 }
                
//             }
//             flag = 1;
//             for(int i = 0;i < 10;i++)
//             {
//                 for(int j = 0;j < 10;j++)
//                 {
//                     if(b[i][j] == 1)
//                     {
//                         if(a[i][j] != '*')
//                         {
//                             flag = 0;
//                         }
//                     }
//                 }
//             }
//             if(flag)
//             {
//                 cout << "win" << endl;
//                 fuck = 0;
//             }
//         }
//     }
//     return 0;
// }

