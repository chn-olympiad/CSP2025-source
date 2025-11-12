#include <iostream>

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int m, //all \ch::lie
        n; //all \ch::hang
    std::cin >> n >> m;
    int a[n * m], //Score of all students
        x,        //X Xiao's Score
        wx;       //X Xiao's Award
    for (int i = 0; i < m * n; i++)
    {
        std::cin >> a[i];
    }
    x = a[0];
    bool ct = true; //As the end of "sort,cycle",true:continue,otherwise:break
    while (ct)
    {
        ct = false;
        for (int i = 0; i < n * m - 1; i++)
        {
            if (a[i] < a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                ct = true;
            }
        }
    }
    for (int i = 0; i < m * n; i++)
    {
        if (a[i] == x)
        {
            wx = (i + 1);
            break;
        }
    }
    int c, //X Xiao's \ch::lie
        r; //X Xiao's \ch::hang
    c = wx / n;
    if (wx % n)
        c++;
    wx -= (c-1) * n;
    if (!wx)
    {
        if (c % 2)
            r = n;
        else
            r = 1;
    }
    if (c % 2)
        r = wx;
    else
        r = n - wx + 1;
    if (!r)
        r = n;
    std::cout << c << " " << r;
    fclose(stdout);
    fclose(stdin);
    return 0;
}